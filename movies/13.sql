SELECT stars.person_id FROM stars
JOIN people ON stars.person_id = people.id
WHERE people.name = 'Kevin Bacon'
AND people.birth = '1958';