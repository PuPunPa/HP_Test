Simple algorithm that crawls through whole numbers one by one to each side of zero in order to try and find the whole number solutions for F(x) = 0 through brute force.

It uuses no search or interpolation arlgorithms since they only output one root based on the initial guess, and since these are blind guesses anyway I preferred to stick to the more reliable yet more inefficient solution

Program execution ends once it looks through 0 to ±1,000,000, or it finds all 3 roots, in case the former happens it will print however many roots it found during execution.
