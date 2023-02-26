SELECT movies.title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.id IN
(SELECT people.id FROM people
WHERE people.name = 'Johnny Depp')
AND people.id IN
(SELECT people.id FROM people
WHERE people.name = 'Helena Bonham Carter')