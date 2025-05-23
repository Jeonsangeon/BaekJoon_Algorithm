SELECT
    YEAR(DIFFERENTIATION_DATE) AS YEAR,
    (MAX_YEAR - SIZE_OF_COLONY) AS YEAR_DEV,
    ID
FROM
    (SELECT
            *,
            MAX(SIZE_OF_COLONY) OVER(PARTITION BY YEAR(DIFFERENTIATION_DATE)) AS MAX_YEAR
        FROM
            ECOLI_DATA) AS F
ORDER BY YEAR(DIFFERENTIATION_DATE), YEAR_DEV