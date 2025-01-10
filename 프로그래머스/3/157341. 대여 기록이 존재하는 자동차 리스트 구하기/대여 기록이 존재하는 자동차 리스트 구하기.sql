SELECT
    DISTINCT(F.CAR_ID)
FROM
    CAR_RENTAL_COMPANY_CAR AS F INNER JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY AS S
    ON F.CAR_ID = S.CAR_ID
WHERE
    F.CAR_TYPE = '세단' AND YEAR(S.START_DATE) = 2022 AND MONTH(S.START_DATE) = 10
ORDER BY
    F.CAR_ID DESC