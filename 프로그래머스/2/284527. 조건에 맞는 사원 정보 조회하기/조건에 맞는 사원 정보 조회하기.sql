-- 코드를 작성해주세요
select sum(b.SCORE) as SCORE, a.EMP_NO, a.EMP_NAME, a.POSITION, a.EMAIL
from HR_EMPLOYEES a, HR_GRADE b
where a.EMP_NO = b.EMP_NO
group by EMP_NO
order by SCORE desc
limit 1