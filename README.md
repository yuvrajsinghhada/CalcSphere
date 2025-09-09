# Numerical Recipes
A simple numerical analysis tool which can perform differentiation, integration and root approximation for functions using a multitude of methods. For description of each of these methods, refer to [Numerical Analysis](https://github.com/paraskhosla3903/numerical-recipes/blob/main/Numerical-Analysis.pdf).

## Computational Capabilites
- [Numerical Differentiation](https://en.wikipedia.org/wiki/Numerical_differentiation)
- [Numerical Integration](https://en.wikipedia.org/wiki/Numerical_integration)
  - [Riemann Sum](https://en.wikipedia.org/wiki/Riemann_sum)
      - [Left Riemann Sum](https://en.wikipedia.org/wiki/Riemann_sum#Left_rule)
      - [Right Riemann Sum](https://en.wikipedia.org/wiki/Riemann_sum#Right_rule)
      - [Midpoint Rule](https://en.wikipedia.org/wiki/Riemann_sum#Midpoint_rule)
      - [Trapezoidal Rule](https://en.wikipedia.org/wiki/Riemann_sum#Trapezoidal_rule)
  - [Simpsons' Rule](https://en.wikipedia.org/wiki/Simpson%27s_rule)
- [Root Approximation](https://en.wikipedia.org/wiki/Root-finding_algorithms)
  - [Newton-Raphson Method](https://en.wikipedia.org/wiki/Newton%27s_method)
  - [Bisection Method](https://en.wikipedia.org/wiki/Bisection_method)
  - [Secant Method](https://en.wikipedia.org/wiki/Secant_method)

## Key Features
- **User-defined Precision**: The program gives the freedom of choosing the degree of precision upto which the result is required. This is specified by the parameter `eps` which stands for $\epsilon$.
- **Maximum Iterations**: User can define the maximum number of iterations of the program. Program terminates for whichever of the two conditions is met first, whether the required precision is reached, or the maximum iterations have elapsed.
- **Calculator History**: The most useful of this application is perhaps that it stores the result for each iteration in a .txt file so that the user can analyse how the function behaves after each iteration, this also gives away the trend of how the result is reached. For example, the function call `fprintNewtonRaphson(f,eps,x,maxIterations)` for $f(x)=e^{x}-10$ results in the following .txt file.

  <p align="center">
  <img src="https://raw.githubusercontent.com/paraskhosla3903/numerical-recipes/main/calc-history.png" alt="Calculator History" width=825 height=235/>
  </p>

## Limitations
- **Function Input**: It is challenging to take function input from the CLI. One of the solutions could be to map certain strings to functions in the `<math.h>` library in C using macros, but that is rather tedious and non-elegant.
- **Derivative Error Term**: The function `derivative(f,x0)` is called numerous times from within multiple functions. This function itself is not error free, therefore it adds to the number of iterations required for reaching the desired level of precision in the result.

## Future Scope
- **LaTeX Compilation**: Additional functionality of typesetting the result and storing it in a .pdf format could be introduced. For example if user computes the approximation of the [Gaussian Integral](https://en.wikipedia.org/wiki/Gaussian_integral) using the bounds from -5 to +5, which results in only an error of around $10^{-12}$, we could depict this as under in a .pdf output file.

$$\int_{-5}^{+5}e^{-x^{2}}dx\approx 1.77245$$

- **Additional Methods**: More advanced computational techniques could be incorporated into the program to improve the computation time and increase the degree of precision reached at lower number of iterations. For instance, [Regula-Falsi](https://en.wikipedia.org/wiki/Regula_falsi#Numerical_analysis), [Ridders' Method](https://en.wikipedia.org/wiki/Ridders%27_method) for Root Finding, [Monte Carlo Method](https://en.wikipedia.org/wiki/Monte_Carlo_integration) for Numerical Integration etc.

- **Game Base**: The logic laid out in this program could be used to construct a gamified educational tool that generates a mathematical expression on screen and takes in user input. If user inputs a value within a preset error bound of the actual value of the expression, which could be basis for the difficulty level of the game, the input gets classified as _good_ and the user is awarded points correspondingly.

