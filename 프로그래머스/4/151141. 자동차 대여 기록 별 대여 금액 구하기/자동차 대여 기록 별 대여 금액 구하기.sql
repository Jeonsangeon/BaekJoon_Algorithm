WITH CC AS (
SELECT
    RS.HISTORY_ID,
    RS.DAILY_FEE,
    DATEDIFF(END_DATE, START_DATE) + 1 AS RENTAL_DATE,
    CASE
        WHEN DATEDIFF(END_DATE, START_DATE) + 1 >= 90 THEN '90일 이상'
        WHEN DATEDIFF(END_DATE, START_DATE) + 1 >= 30 THEN '30일 이상'
        WHEN DATEDIFF(END_DATE, START_DATE) + 1 >= 7 THEN '7일 이상'
        ELSE '할인 없음'
    END AS DURATION_TYPE
FROM(
    SELECT
        F.DAILY_FEE,
        S.*
    FROM
        CAR_RENTAL_COMPANY_CAR AS F INNER JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY AS S
        ON F.CAR_ID = S.CAR_ID
    WHERE
        F.CAR_TYPE = '트럭') AS RS
),

DP AS (
    SELECT  
        DURATION_TYPE,
        REGEXP_REPLACE(DISCOUNT_RATE, '[^0-9]+', '') AS DISCOUNT_RATE
    FROM
        CAR_RENTAL_COMPANY_DISCOUNT_PLAN
    WHERE
        CAR_TYPE = '트럭'
)

SELECT
    RF.HISTORY_ID,
    ROUND(RF.DAILY_FEE * RF.RENTAL_DATE * (100 - RF.DISCOUNT_RATE) * 0.01) AS FEE
FROM(
    SELECT
        HISTORY_ID,
        DAILY_FEE,
        RENTAL_DATE,
        IFNULL(DISCOUNT_RATE, 0) AS DISCOUNT_RATE
    FROM
        CC LEFT JOIN DP ON CC.DURATION_TYPE = DP.DURATION_TYPE) AS RF
ORDER BY FEE DESC, RF.HISTORY_ID DESC