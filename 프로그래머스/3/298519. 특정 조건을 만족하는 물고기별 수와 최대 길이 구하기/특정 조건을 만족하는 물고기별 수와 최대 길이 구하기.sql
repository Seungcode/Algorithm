-- 코드를 작성해주세요
# 평균 길이가 33이상인 물고기들을 종류별로 -> ID대로 GROUP BY
# 10cm 이하일 경우 -> 10cm로 분류
# 고기 종류에 대해 오름차순 정렬
# 칼럼명 FISH_TYPE, FISH_COUNT, MAX_LENGTH

SELECT COUNT(*) AS FISH_COUNT, MAX(LENGTH) AS MAX_LENGTH, FISH_TYPE
FROM FISH_INFO
GROUP BY FISH_TYPE
HAVING AVG(ifnull(LENGTH, 10)) >= 33
ORDER BY FISH_TYPE;

# 후기 : HAVING절에서도 ifnull을 통해 조건을 부여할 수 있다..!
