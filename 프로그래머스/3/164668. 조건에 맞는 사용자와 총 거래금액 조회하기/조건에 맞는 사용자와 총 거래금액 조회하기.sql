SELECT
    S.USER_ID, S.NICKNAME, SUM(F.PRICE) AS TOTAL_SALES
FROM
    USED_GOODS_BOARD AS F INNER JOIN USED_GOODS_USER AS S
    ON F.WRITER_ID = S.USER_ID
WHERE
    F.STATUS = "DONE"
GROUP BY
    F.WRITER_ID
HAVING 
    SUM(F.PRICE) >= 700000
ORDER BY
    TOTAL_SALES