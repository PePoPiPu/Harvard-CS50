SELECT movies.title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE movies.id IN
(SELECT stars.movie_id
WHERE people.id IN )
AND movies.id IN
(SELECT stars.movie_id
WHERE people.name = 'Helena Bonham Carter')