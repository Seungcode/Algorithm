# 서브쿼리에서 열의 순서 계산 -> ROW_NUMBER() -> 기주을 세우고 그에 따른 순서를 받아옴
# 백분위수와의 비교
SELECT 
    A.ID, 
    (CASE 
        WHEN A.ranking <= total_count * 0.25 THEN "CRITICAL"
        WHEN A.ranking <= total_count * 0.5 THEN "HIGH"
        WHEN A.ranking <= total_count * 0.75 THEN "MEDIUM"
        ELSE "LOW"
    END) AS COLONY_NAME
FROM 
    (SELECT 
        ID,
        ROW_NUMBER() OVER (ORDER BY SIZE_OF_COLONY DESC) AS ranking
    FROM 
        ECOLI_DATA) AS A,
    (SELECT COUNT(*) AS total_count FROM ECOLI_DATA) AS B
ORDER BY 
    A.ID;
