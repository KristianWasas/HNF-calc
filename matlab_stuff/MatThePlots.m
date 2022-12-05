a = 64;
x = 1:a;

mattimes = zeros(a, 1);

for i = x
    M = randi([-99 99],i,i);
    tic
    hermiteForm(M);
    mattimes(i) = toc;
end

figure(1)
semilogy(x, 10^-9*resultsv2(x, :), x, 10^-9*resultsv4(x, :), x, mattimes);
xlabel("Size NxN");
ylabel("Time in seconds");
legend("Naive implementation C++", "Optimized implementation C++", "Matlab hermiteForm function");
