SELECT people.name FROM people
WHERE people.id IN
(SELECT stars.person_id FROM stars
WHERE stars.movie_id IN
(SELECT stars.movie_id
WHERE stars.person_id ))