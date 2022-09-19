-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Humphrey Street";

-- 10:15am @ humphrey Street bakery 3 Witnesses

SELECT *
FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute = 15;

-- ID = 258 Entered the store @ 10:08 License_plate = R3G7486
-- ID = 259 @ 10:14 License_plate = 13FNH73
SELECT *
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;

-- Partner bought the first flight out of Fiftyville for 7/29/2021
--  | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
--  | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
--  | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
--  | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
--  | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
--  | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
--  | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
--  | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
--  | 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58       |