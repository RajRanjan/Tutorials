#This files deals with the learning of nodejs language
```
Data-Types
variables
-The default value of any variable in JavaScript is undefined. 
numbers
```
booleans
Arrays

Object Literals
-By explaining these few fundamental types, we have introduced you to object literals. The most common way of creating an object in JavaScript is using the object notation, {}. Objects can be extended arbitrarily at runtime.
-a nonexistent property on a object or variable returns undefined




*Console OBJEct
This is a global variable
console objet contains some functions like log

Functions
-All functions return a value in JavaScript. In the absence of an explicit return statement, a function returns undefined. 
-Immediately Executing Function You can execute a function immediately after you define it. Simply wrap the function in parentheses () and invoke it. 
-Anonymous Function  A function without a name is called an anonymous function. In JavaScript, you can assign a function to a variable. If you are going to use a function as a variable, you don’t need to name the function.
-A programming language is said to have first-class functions if a function can be treated the same way as any other variable in the language. JavaScript has first-class functions.
-Higher-Order Functions   Since JavaScript allows us to assign functions to variables, we can pass functions to other functions. Functions that take functions as arguments are called higher-order functions. A very common example of a higher-order function is setTimeout. 



Closures
- Whenever we have a function defined inside another function, the inner function has access to the variables declared in the outer function. 
- Now the awesome part: The inner function can access the variables from the outer scope even after the outer function has returned. This is because the variables are still bound in the inner function and not dependent on the outer function.

The I/O Scaling Problem
-Most web applications depend on reading data from disk or from another network source (for example, a database query). When an HTTP request is received and we need to load data from a database, typically this request will be spent waiting for a disk read or a network access call to complete.
-Modern web applications use thread pool
-traditional web servers initiated a separate proccess for each new request which was tiresome
-now a days we use thread pool for that


Traditional Web Servers Using a Process Per Request
-Traditional servers used to spin up a new process to handle every single web request. Spinning a new process for each request is an expensive operation, both in terms of CPU and memory. This is the way technologies like PHP used to work when they were first created.
A demonstration of this concept is shown in Figure 2-2. In order to successfully reply to an HTTP request “A,” we need some data from a database. This read can potentially take a long time. For this entire read duration, we will have a process taking up CPU and memory while idling and waiting for the database response. Also, processes are slow to start and have a significant overhead in terms of RAM space. This does not scale for very long and that is the reason why modern web applications use a thread pool.


Traditional Web Servers Using a Thread Pool
-Modern servers use a thread from a thread pool to serve each request. Since we already have a few Operating System (OS) threads created (hence a thread pool), we do not pay the penalty of starting and stopping OS processes (which are expensive to create and take up much more memory than a thread). When a request comes in, we assign a thread to process this request. This thread is reserved for the request in the entire duration that the request is being handled, as demonstrated in Figure 2-3.Because we save the overhead of creating a new process every time and the threads are lighter than processes, this method is much better than the original server design. Most web servers used this method a few years back and many continue to use today. However, this method is not without drawbacks. Again there is wasting of RAM between threads. Also the OS needs to context switch between threads (even when they are idle), and this results in wasted CPU resources.



The Nginx Way
Nginx is a single-threaded web server and can handle a tremendous amount of concurrent requests.



Exact Equality
--One thing to be careful about in JavaScript is the difference between == and ===. As JavaScript tries to be resilient against programming errors, == tries to do type coercion between two variables. For example, it converts a string to a number so that you can compare it with a number


null
-null is a special JavaScript object used to denote an empty object. This is different from undefined, which is used
by JavaScript for nonexistent and noninitialized values. You should not set anything to undefined because, by convention, undefined is the default value you should leave to the runtime. A good time to use null is when you want to explicitly say that something is not there, such as as a function argument. 



Revealing Module Pattern
-Functions that return objects are a great way to create similar objects.
-At the heart of the revealing module pattern is JavaScript’s support for closures and ability to return arbitrary (function + data) object literals. 
- in module revealing pattern we always get a new object when we call that function.
-Functions that return objects are a great way to create similar objects. An object here means data and functionality bundled into a nice package, which is the most basic form of Object Oriented Programming (OOP) that one can do. At the heart of the revealing module pattern is JavaScript’s support for closures and ability to return arbitrary (function + data) object literals. Listing 2-33 is a simple example that shows how to create an object using this pattern.
Listing 2-33. revealingModules.js
function printableMessage() {
    var message = 'hello';
    function setMessage(newMessage) {
        if (!newMessage) throw new Error('cannot set empty message');
        message = newMessage;
    }
    function getMessage() {
        return message;
}
    function printMessage() {
        console.log(message);
}
    return {
        setMessage: setMessage,
        getMessage: getMessage,
        printMessage: printMessage
}; }
// Pattern in use
var awesome1 = printableMessage();
awesome1.printMessage(); // hello
var awesome2 = printableMessage();
awesome2.setMessage('hi');
awesome2.printMessage(); // hi
// Since we get a new object everytime we call the module function
// awesome1 is unaffected by awesome2
awesome1.printMessage(); // hello
The great thing about this example is that it is a simple pattern to understand because it only utilizes closures, first-class functions, and object literals—concepts that are already familiar to you and that we covered extensively in the beginning of this chapter.