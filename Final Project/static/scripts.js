document.addEventListener("DOMContentLoaded", => {
    function validateForm() {
        let x = document.forms["login"]["username"].value;
        let y = document.forms.["login"]["username"].value;
        if (x == "") {
            alert("Username must be filled out");
            return false;
        }
        else if (y == "") {
            alert("Password must be filled out")
        }
    }
})