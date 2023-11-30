-- Keep a log of any SQL queries you execute as you solve the mystery.


-- check the crime_scene_reports in that time
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';


-- check the interview in that time , The witnesses could be the accomplice.
SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;


-- we found 2 eugene , so we want check more about this.
SELECT name FROM people WHERE name = 'eugene';


-- we found 3 witness , Witnesses are- eugene, raymond, and ruth.
SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%' ORDER BY name;


-- eugene : Thief was withdrawing money from the ATM on Leggett Street. So, we nead to check.
SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- we need to research in the banck(ATM)
SELECT name, atm_transactions.amount FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw';


-- Raymond : As leaving the bakery, they called a person and talked for less than a minute. They asked the person on the other end of the call to buy a flight ticket of the earliest flight on July 29, 2021. so we need check the airports
SELECT abbreviation, full_name, city FROM airports WHERE city = 'Fiftyville';


-- we need check with details about that clues
SELECT flights.id, full_name, city, flights.hour, flights.minute FROM airports JOIN flights ON airports.id = flights.destination_airport_id WHERE flights.origin_airport_id =(SELECT id FROM airports WHERE city = 'Fiftyville') AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29ORDER BY flights.hour, flights.minute;


-- First flight comes out to be at 8:20 to LaGuardia Airport in New York City (Flight id- 36). This could be the place where the thief went to , so we need to check the passport of passengers
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat FROM people JOIN passengers ON people.passport_number = passengers.passport_number  JOIN flights ON passengers.flight_id = flights.id WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flights.hour = 8 AND flights.minute = 20 ORDER BY passengers.passport_number;


-- we need to check the phone call of passenger looks like that clues
SELECT name, phone_calls.duration FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60 ORDER BY phone_calls.duration;


-- checking the possible names of the call-receiver
SELECT name, phone_calls.duration FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60 ORDER BY phone_calls.duration;


-- Ruth : The thief drove away in a car from the bakery, within 10 minutes from the theft. so we need to check of linces of car near of bakery (in the cvv2)
SELECT name, bakery_security_logs.hour, bakery_security_logs.minute FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.activity = 'exit' AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25 ORDER BY bakery_security_logs.minute;

-- I think the Bruce is thief because he is present in the all time and everywhere and He must have escaped to the New York City, as he took the New York City flight.
-- Robin must be the accomplice who purchased the flight ticket, and helped Bruce escape to the New York City. so we found the helper and thief , thats was weird , why Bruce want to take the duck ?
--  anyway we found the thief so maybe we are the officer in the net