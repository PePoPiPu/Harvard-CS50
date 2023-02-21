SELECT people.id FROM people
WHERE people.id IN
(SELECT stars.person_id, stars.movie_id FROM stars
JOIN people ON stars.person_id = people.id
WHERE people.name = 'Kevin Bacon'
AND people.birth = '1958');