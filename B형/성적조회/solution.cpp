#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;

struct Student{

    int Id;
    int Score;
    int Grade;
    int Gender;

    bool operator < (const Student& t) const {
        if(Score == t.Score){
            return Id < t.Id;
        }
        return Score < t.Score;
    }
};

unordered_map<int,Student> HashId;
set<Student> TreeSet[4][2]; // 학년, 성별

void init() {
    for(int i=1;i<=3;i++){
        for(int j=0;j<2;j++) TreeSet[i][j].clear();
    }
    HashId.clear();
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {

    string str = mGender;
    Student tmp;
    tmp.Id = mId;
    tmp.Grade = mGrade;
    tmp.Gender = (str == "male" ? 0 : 1);
    tmp.Score = mScore;

    TreeSet[tmp.Grade][tmp.Gender].insert(tmp);
    HashId[mId]=tmp;

	return (--TreeSet[tmp.Grade][tmp.Gender].end())->Id;
}

int remove(int mId) {
    auto f = HashId.find(mId);
    if(f==HashId.end()){
        return 0;
    }else{
        Student tmp = f->second;
        auto TreeFind = TreeSet[tmp.Grade][tmp.Gender].find(tmp);
        TreeSet[tmp.Grade][tmp.Gender].erase(TreeFind);
        HashId.erase(mId);
        if(TreeSet[tmp.Grade][tmp.Gender].size()){
            return TreeSet[tmp.Grade][tmp.Gender].begin()->Id;
        }
        else return 0;
    }
	
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {

    Student MinStudent;
    MinStudent.Id = -1;
    for(int i=0;i<mGradeCnt;i++){
        for(int j=0;j<mGenderCnt;j++){
            string str = mGender[j];
            int ge = (str== "male" ? 0 : 1);
            auto it = TreeSet[mGrade[i]][ge].lower_bound({0,mScore,0,0});
            if(it == TreeSet[mGrade[i]][ge].end()) continue; // mScore 이상 없음
            if(MinStudent.Id==-1 || *it < MinStudent){
                MinStudent = *it;
            }
        }
    }
    if(MinStudent.Id == -1){// 전체에서 mScore 이상 없음
        return 0;
    }
    else{
        return MinStudent.Id;
    }
}