-- 코드를 작성해주세요
# CASE문 사용 -> 가정이 3개 -> if보다 CASE가 편리할듯
SELECT ID, (CASE WHEN SIZE_OF_COLONY <= 100 THEN "LOW"
            WHEN SIZE_OF_COLONY <= 1000 THEN "MEDIUM"
            ELSE "HIGH" 
            END) AS SIZE
FROM ECOLI_DATA
ORDER BY ID;
