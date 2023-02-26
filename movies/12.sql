SELECT movies.title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.id IN
(SELECT stars.person_id FROM stars
WHERE people.name = 'Johnny Depp');