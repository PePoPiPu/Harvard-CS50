document.addEventListener("DOMContentLoaded", => {

    // Getting the form, the username input vox and the span element
    // into which I'm placing the error message
    const form = document.querySelector("form");
    const username = document.getElementById("username")
    const usernameError = document.querySelector("#username + span.error")

    email.addEventListener("input", (event) => {
        // Checking if the form fields are valid
        // Each time a user inputs something

        if (username.validity.valid) {
            // Removing error message if there's an error message and the input is valid
            usernameError.textContent
        }
    })
})