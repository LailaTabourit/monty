
<img src="https://camo.githubusercontent.com/b32fc84889b63b30d73d84553419e4190d552be0e75b28f106478bb3c1859798/68747470733a2f2f7777772e6765656b73756c74642e636f6d2f77702d636f6e74656e742f75706c6f6164732f323032302f30352f4d6f6e74792d537461636b732d5175657565732e6a7067" alt="Monty Logo">
  <h2>0x19. C - Stacks, Queues - LIFO, FIFO</h2>
  <ul>
    <li>This project is done in teams of 2 people.</li>
    <li>Team: Laila Tabourit, Zakaria Berahmi</li>
  </ul>
  
  <h2>The Monty Language</h2>
  <p>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</p>
  
  <h2>Monty Byte Code Files</h2>
  <p>Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:</p>
  
  <pre>
    <code>
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
    </code>
  </pre>
  
  <p>Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not taken into account:</p>
  
  <pre>
    <code>
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
    </code>
  </pre>
  
  <h2>The Monty Program</h2>
  <h3>Usage:</h3>
  <p>monty file</p>
  <p>where file is the path to the file containing Monty byte code</p>
  <ul>
    <li>If the user does not give any file or more than one argument to your program, print the error message <code>USAGE: monty file</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
    <li>If, for any reason, it’s not possible to open the file, print the error message <code>Error: Can't open file &lt;file&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>, where <code>&lt;file&gt;</code> is the name of the file</li>
    <li>If the file contains an invalid instruction, print the error message <code>L&lt;line_number&gt;: unknown instruction &lt;opcode&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>, where <code>&lt;line_number&gt;</code> is the line number where the instruction appears. Line numbers always start at 1</li>
    <li>If you can’t malloc anymore, print the error message <code>Error: malloc failed</code>, followed by a new line, and exit with status <code>EXIT_FAILURE</code>. You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)</li>
  </ul>
  
  <h3>Usage Example:</h3>
  <pre><code>./monty bytecode_file</code></pre>
  
  <h2>Available Operation Codes:</h2>
  <table>
    <tr>
      <th>Opcode</th>
      <th>Description</th>
    </tr>
    <tr>
      <td>push</td>
      <td>Pushes an element to the stack. e.g (push 1 # pushes 1 into the stack)</td>
    </tr>
    <tr>
      <td>pall</td>
      <td>Prints all the values on the stack, starting from the top of the stack.</td>
    </tr>
    <tr>
      <td>pint</td>
      <td>Prints the value at the top of the stack.</td>
    </tr>
    <tr>
      <td>pop</td>
      <td>Removes the top element of the stack.</td>
    </tr>
    <tr>
      <td>swap</td>
      <td>Swaps the top two elements of the stack.</td>
    </tr>
    <tr>
      <td>add</td>
      <td>Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.</td>
    </tr>
    <tr>
      <td>nop</td>
      <td>This opcode does not do anything.</td>
    </tr>
    <tr>
      <td>sub</td>
      <td>Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.</td>
    </tr>
    <tr>
      <td>div</td>
      <td>Divides the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.</td>
    </tr>
    <tr>
      <td>mul</td>
      <td>Multiplies the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.</td>
    </tr>
    <tr>
      <td>mod</td>
      <td>Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.</td>
    </tr>
    <tr>
      <td>#</td>
      <td>When the first non-space of a line is a # the line will be treated as a comment.</td>
    </tr>
    <tr>
      <td>pchar</td>
      <td>Prints the integer stored in the top of the stack as its ASCII value representation.</td>
    </tr>
    <tr>
      <td>pstr</td>
      <td>Prints the integers stored in the stack as their ASCII value representation. It stops printing when the value is 0, when the stack is over, or when the value of the element is a non-ASCII value.</td>
    </tr>
    <tr>
      <td>rotl</td>
      <td>Rotates the top of the stack to the bottom of the stack.</td>
    </tr>
    <tr>
      <td>rotr</td>
      <td>Rotates the bottom of the stack to the top of the stack.</td>
    </tr>
    <tr>
      <td>stack</td>
      <td>This is the default behavior. Sets the format of the data into a stack (LIFO).</td>
    </tr>
    <tr>
      <td>queue</td>
      <td>Sets the format of the data into a queue (FIFO).</td>
    </tr>
  </table>
  
  <h3>Error Handling</h3>
  <p>When a nonexistent opcode is passed, the interpreter prints an error message and stops:</p>
  
  <pre><code>
$ cat errorfile.m
push 1
pint
pcx
$ ./monty errorfile.m
1
L3: unknown instruction pcx
  </code></pre>
  
  <h2>Return Value</h2>
  <p>When there are no errors, monty returns 0. Otherwise, it returns 1.</p>
  
  <h2>Authors</h2>
  <ul>
    <li>Laila Tabourit</li>
    <li>Zakaria Berahmi</li>
  </ul>
<h6>For more info check this : </h6>
<code><a href="https://www.scaler.com/topics/application-of-linked-list/](https://data-flair.training/blogs/stacks-and-queues-in-c/)https://data-flair.training/blogs/stacks-and-queues-in-c/">stacks & queues</a></code>
<code><a href="https://www.scaler.com/topics/application-of-linked-list/](https://www.digitalocean.com/community/tutorials/stack-in-c)">How To Implement a Stack in C Programming</a></code>
<code><a href="https://www.scaler.com/topics/application-of-linked-list/](https://data-flair.training/blogs/stacks-and-queues-in-c/)https://data-flair.training/blogs/stacks-and-queues-in-c/](https://www.edureka.co/blog/queue-in-c/)">How To Implement Queue in C?</a></code>

  <p> 
  <h2 id="license">License</h2>
  <p>&copy; 2023 Laila Tabourit & Zakaria Berahmi</p>
    This repository is licensed under the MIT License. See the <a href="LICENSE">LICENSE</a> file for more information.
  </p>  
