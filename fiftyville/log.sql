-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Humphrey Street";

-- 10:15am @ humphrey Street bakery 3 Witnesses

SELECT *
FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10;

-- ID = 258 Entered the store @ 10:08 License_plate = R3G7486
-- ID = 259 @ 10:14 License_plate = 13FNH73
SELECT *
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;

-- Partner bought the first flight out of Fiftyville for 7/29/2021
-- Leggett Street atm before 10:15 am
-- Phonecall after 10:15 AM < 1 min
--  | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
--  | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
--  | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
--  | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
--  | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
--  | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
--  | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
--  | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
--  | 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58       |

SELECT *
FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';
-- 264, 267 id's that match the id's leaving the bakery after the robbery.

SELECT *
FROM flights
WHERE year = 2021 AND month = 7 AND day = 29
-- FLIGHT id 36

SELECT *
FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE flight_id = 36;

--+--------+--------+----------------+-----------------+---------------+-----------+-----------------+------+
--|   id   |  name  |  phone_number  | passport_number | license_plate | flight_id | passport_number | seat |
--+--------+--------+----------------+-----------------+---------------+-----------+-----------------+------+
--| 953679 | Doris  | (066) 555-9701 | 7214083635      | M51FA04       | 36        | 7214083635      | 2A   |
--| 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       | 36        | 1695452385      | 3B   |
--| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       | 36        | 5773159633      | 4A   |
--| 651714 | Edward | (328) 555-1152 | 1540955065      | 130LD9Z       | 36        | 1540955065      | 5C   |
--| 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       | 36        | 8294398571      | 6C   |
--| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       | 36        | 1988161715      | 6D   |
--| 395717 | Kenny  | (826) 555-1652 | 9878712108      | 30G67EN       | 36        | 9878712108      | 7A   |
--| 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       | 36        | 8496433585      | 7B

SELECT *
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- BRUCE -- Phone number an License plate match and both suspects would not be on the same flight.
-- (375) 555-8161 Phone number of suspect

SELECT name
FROM people
WHERE phone_number = '(375) 555-8161';
-- ROBIN

SELECT destination_airport_id
FROM flights
WHERE id = 36;
-- 4


SELECT full_name
FROM airports
WHERE id = 4;
Laguardia Airport