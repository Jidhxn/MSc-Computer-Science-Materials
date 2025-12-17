// a. Check if the first character of a string is uppercase

function isFirstCharUpper(str) {
    let first = str.charAt(0);
    if (first >= 'A' && first <= 'Z') {
        console.log("First character is uppercase.");
    } else {
        console.log("First character is NOT uppercase.");
    }
}

// Test
isFirstCharUpper("Hello");
isFirstCharUpper("world");



// b. Regular expression for email validation

let emailPattern = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-z]{2,4}$/;

// Test
console.log(emailPattern.test("test@example.com"));     // true
console.log(emailPattern.test("wrong-email@"));         // false




// c. Function to print an integer with commas as thousand separators

function addCommas(num) {
    return num.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
}

// Test
console.log(addCommas(1000));        // 1,000
console.log(addCommas(987654321));   // 987,654,321



// d. JavaScript loop from 0 to 15 checking odd/even

for (let i = 0; i <= 15; i++) {
    if (i % 2 === 0) {
        console.log(i + " is even");
    } else {
        console.log(i + " is odd");
    }
}
