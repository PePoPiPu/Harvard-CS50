-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Getting to know the descriptions and id's of the crimes committed on July 28, 2021.
-- The theft of the CS50 duck has an ID of 295.
-- The crime was committed at 10:15 am.
SELECT id, description FROM crime_scene_reports
    WHERE year = 2021
    AND month = 7
    AND street = 'Humphrey Street';

-- Select the 3 interviews done.
SELECT transcript FROM interviews
    WHERE transcript LIKE '%bakery%';
-- We get 3 pieces of info from this query:
    -- The thief withdrawed some money on Leggett Street before going to the bakery
    -- As the criminal was leaving the bakery, he asked someone on the phone to book the earliest flight out of fiftyville the 29th. The call was less than a minute long.
    -- After the crime, the thief got into a car in the parking lot (look footage in 10:15 am time frame)

-- Let's look at ATM transactions
SELECT * FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND transaction_type = 'withdraw'
AND atm_location = 'Leggett Street';
-- Let's count them
SELECT COUNT(*) FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND transaction_type = 'withdraw'
AND atm_location = 'Leggett Street';

-- We know that 8 withdrawals where made at the atm in Leggett Street. We cannot do much with this info yet.
-- Let's look at phone calls made on July, 28th, 2021
SELECT * FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60;

-- Let's count them
SELECT COUNT(*) FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60;
-- 9 calls where made the 28th that are less than one minute long. We'll narrow it down later.
-- Let's look at the bakery's security logs. The thief left the bakery sometime within ten minutes of the crime that was committed at 10:15.
SELECT * FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute < 25
    AND activity = 'exit';
-- Counting
SELECT COUNT(*) FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute < 25
    AND activity = 'exit';
-- We get a total of 8 license plates that left the parking lot between 10:15 and 10:25.
-- We can start making correlations. Let's start with the names of those who left the parking lot:
SELECT name FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.license_plate IN
    (SELECT bakery_security_logs.license_plate FROM bakery_security_logs)
AND year = 2021
AND month = 7
AND hour = 10
AND minute < 25
AND activity = 'exit'
AND day = 28;
-- Now we got 8 suspects, Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana and Kelsey
-- Let's look up who's phone number matches with the phone calls record
SELECT name, phone_number FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE phone_calls.caller IN
    (SELECT caller FROM phone_calls)
AND year = 2021
AND month = 7
AND day = 28
AND duration < 60
AND name IN ('Vanessa', 'Bruce', 'Barry', 'Luca', 'Sofia', 'Iman', 'Diana', 'Kelsey');

-- Let's see who made a call and exited the parking lot that day:
SELECT name FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE bakery_security_logs.license_plate IN
    (SELECT bakery_security_logs.license_plate FROM bakery_security_logs)
AND phone_calls.caller IN
    (SELECT caller FROM phone_calls)
AND phone_calls.year = 2021
AND phone_calls.month = 7
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute < 25
AND bakery_security_logs.activity = 'exit'
AND phone_calls.duration < 60
AND phone_calls.day = 28
AND name IN ('Vanessa', 'Bruce', 'Barry', 'Luca', 'Sofia', 'Iman', 'Diana', 'Kelsey');
-- This returns a list that includes 1 call made by Bruce, Sofia and Diana and 2 calls made by Kelsey.
-- We can discard Kelsey as a suspect since the info we have from the interviews states that the thief only made 1 call, not 2.
-- Our remaining suspects are Bruce, Sofia and Diana.
-- Let's see which of them withdrew money that day:
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE bank_accounts.account_number IN
    (SELECT account_number FROM atm_transactions)
AND year = 2021
AND month = 7
AND day = 28
AND transaction_type = 'withdraw'
AND atm_location = 'Leggett Street'
AND name IN ('Bruce', 'Sofia', 'Diana');
-- This returns 2 names: Bruce and Diana, which are now our main suspects.
-- Let's see which one of them is in the earliest flight out of fiftyville:
-- First let's find out their passport numbers:
SELECT * FROM passengers
JOIN people ON passengers.passport_number = people.passport_number
WHERE people.name IN ('Bruce', 'Diana');
-- This returns a list with Bruce appearing 1 time and Diana appearing thrice with different seat numbers. Why?
-- Let's find out each flight's airport of origin and airport of destination.
SELECT people.name, airports.full_name, hour, minute FROM passengers
JOIN people ON passengers.passport_number = people.passport_number
    JOIN flights ON passengers.flight_id = flights.id
        JOIN airports ON flights.origin_airport_id = airports.id
WHERE people.name IN ('Bruce', 'Diana')
AND year = 2021
AND month = 7
AND day = 29;
-- This returns a list with Bruce and Diana again! Diana has a flight out of fiftyville at 16:00 and Bruce has one booked at 8:20.
-- Both are booked the day after the crime was comitted.
-- From the info we know from the interviews, the thief told someone to book the earliest flight the next day.
-- We can assume that the thief is Bruce!
-- Let's find where the thief is right now:
SELECT airports.city FROM airports
WHERE airports.id IN
    (SELECT destination_airport_id FROM passengers
    JOIN people ON passengers.passport_number = people.passport_number
        JOIN flights ON passengers.flight_id = flights.id
            JOIN airports ON flights.origin_airport_id = airports.id
    WHERE people.name IN ('Bruce')
    AND year = 2021
    AND month = 7
    AND day = 29);
-- The thief is in New York City right now.

-- Time to find the accomplice.
-- Bruce made a call the day of the theft, let's see who he called.
SELECT phone_calls.receiver FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE people.name = 'Bruce'
AND year = 2021
AND month = 7
AND day = 28
AND duration < 60;
-- This returns the following phone number: (375) 555-8161
-- Let's see who that belongs to:
SELECT name FROM people
WHERE people.phone_number IN
    (SELECT phone_calls.receiver FROM people
    JOIN phone_calls ON people.phone_number = phone_calls.caller
    WHERE people.name = 'Bruce'
    AND year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60);