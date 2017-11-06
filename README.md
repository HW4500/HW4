# HW4

Part 1. Implement the power method to estimate the largest eigenvalue of a covariance matrix, in C. Your program should have a function located in a separate file, by itself, that takes as input the entire time series (in some data structure), and then returns the eigenvalue estimation (after computing the covariance matrix). Test your code on a small time series, and then use the time series we provided for HW3, with data for 1000 assets over 250 days.

Part 2. Use the code developed in Part 1 to create a DLL with the same functionality. Test the DLL from within VBA so that you can run the code from a spreadsheet that comes with the time series.

EXTRA CREDIT. Adapt your code so that you can estimate the leading eigenvalue using a rolling horizon of 30 days. That is to say, first you apply the power method to the covariance matrix obtained from days 1-30, then for days 2-31, then 3 - 32, and so on. Part of the task is to quickly update the covariance matrix rather than computing it from scratch. And can you think of a way to jump-start the power method? The computation returns the set of eigenvalue estimates.

