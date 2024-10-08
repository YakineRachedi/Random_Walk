# An example of inheritance with a random walk :

Consider the simple random walk $(S_n)_{n \geq 0}$ defined for all $n \geq 0$ by $S_n = \sum_{k=1}^{n} X_k$, where the $X_k$ are independent random variables such that $P(X_k = 1) = p$ and $P(X_k = -1) = 1 - p$. We wish to simulate this random walk and the process $(M_n)_{n \in \mathbb{N}}$ defined by $M_n = \min(S_0, \dots, S_n)$.


The second class inherits from the previous one and adds the computation of the current absolute minimum ($M_n$).

### _Note_: 
`virtual` cannot be used in a function template. See the documentation for details.
In this case, to use `virtual`, you must remove the function template and use a single pseudo-random number generator.