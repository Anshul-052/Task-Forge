document.getElementById('contact-form').addEventListener('submit', function(event) {
    event.preventDefault();
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const message = document.getElementById('message').value;

    // Display a confirmation message (this can be replaced with an actual email service)
    document.getElementById('form-message').innerText = `Thank you, ${name}! Your message has been sent.`;
    
    // Optionally, reset the form
    this.reset();
});

// Function to handle course enrollment
function enroll(courseName) {
    alert(`You have successfully enrolled in ${courseName}!`);
}
