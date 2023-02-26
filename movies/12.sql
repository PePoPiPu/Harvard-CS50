SELECT movies.title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE stars.movie_id IN
(SELECT stars.movie_id FROM stars
WHERE stars.movie_id IN
(SELECT stars.movie_id FROM stars
WHERE people.name = 'Johnny Depp'));
