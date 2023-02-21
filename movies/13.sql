SELECT stars.person_id FROM stars
JOIN stars ON people.id = stars.person_id
WHERE people.name = 'Kevin Bacon'
AND people.birth = '1958';