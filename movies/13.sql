SELECT people.name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id

SELECT stars.person_id FROM stars
WHERE stars.movie_id IN
(SELECT movies.id FROM movies
WHERE people.name = 'Kevin Bacon'
AND people.birth = '1958');


SELECT people.name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name IN
(SELECT movies.title FROM movies
WHERE stars.movie_id IN
(SELECT movies.id FROM movies
WHERE people.name = 'Kevin Bacon'
AND people.birth = '1958'));

Test code
SELECT people.name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE stars.person_id IN
(SELECT people.id FROM people
WHERE people.name IN
(SELECT people.id FROM people
WHERE movies.title IN
(SELECT movies.title FROM movies
WHERE people.name = 'Kevin Bacon'
AND people.birth = '1958')));