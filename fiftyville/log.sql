-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Humphrey Street";

-- 10:15am @ humphrey Street bakery 3 Witnesses

SELECT *
FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute = 15;
