-- 코드를 입력하세요
SELECT CATEGORY, sum(b.SALES) as TOTAL_SALES
from BOOK a, BOOK_SALES b
where a.BOOK_ID = b.BOOK_ID AND b.SALES_DATE like '2022-01%'
group by a.CATEGORY
order by a.CATEGORY
