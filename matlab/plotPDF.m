function [x,y,f] = plotPDF(data,bins)
[y,x] = hist(data,bins);

norm = 1/(diff(x(1:2))*sum(y));
y = y*norm;
% f = fit(x.',y.','gauss1','Lower',[0 -1e-10 0],'Upper',[Inf 1e-10 Inf]);
f = fit(x.',y.','gauss1');

hold on
plot(f,x,y);
xlabel('$x_\alpha$');
ylabel('$f(x_\alpha)$');

end
