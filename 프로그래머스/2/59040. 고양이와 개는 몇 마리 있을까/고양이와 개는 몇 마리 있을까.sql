-- 코드를 입력하세요
SELECT ANIMAL_TYPE, count(ANIMAL_ID) as count
from ANIMAL_INS
where ANIMAL_TYPE IN ('Cat', 'Dog')
group by ANIMAL_TYPE
order by ANIMAL_TYPE
