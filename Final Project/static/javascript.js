document.addEventListener("DOMContentLoaded", () => {
    // Getting the form, the username input box and the span element
    // into which I'm placing the error message
    const form = document.querySelector("form");
    const username = document.getElementById("username")
    const usernameError = document.querySelector("#username + span.error")
    const password = document.getElementById("password")
    const passwordError = document.querySelector("#password + span.error2")

    username.addEventListener("input", (event) => {
        // Checking if the form fields are valid
        // Each time a user inputs something

        if (username.validity.valid) {
            // Removing error message if there's an error message and the input is valid
            usernameError.textContent = "";
            usernameError.className = "error"
        }
    });

    password.addEventListener("input", (event) => {

        if (password.validity.valid) {

            passwordError.textContent = "";
            passwordError.className = "error"
        }
    })

    form.addEventListener("submit", (event) => {
        if (!username.validity.valid) {
            showError();
            event.preventDefault();
        }

        if (!password.validity.valid) {
            showError();
            event.preventDefault();
        }
    });

    function showError() {
        if (username.validity.valueMissing) {
            // If the fiel is empty, display the following
            usernameError.textContent = "Username required."
        }
        usernameError.className = "error active";

        else if (password.validity.valueMissing) {
            passwordError.textContent = "Password required"
        }
        passwordError.className = "error active";
    }
});