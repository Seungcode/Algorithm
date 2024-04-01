-- 코드를 작성해주세요
# 부모의 ID를 기준으로 함
# 해당 ID를 기준으로 서브쿼리에서 자식의 수를 세어준 후 정렬
SELECT ID, 
(SELECT COUNT(*) FROM ECOLI_DATA WHERE PARENT_ID = E.ID) AS CHILD_COUNT
FROM ECOLI_DATA AS E
ORDER BY ID;