function [tval,tindex] = tvalue(x,y,value)
% value is between 0 and 1

dx = x(2) - x(1);
[~,index_0] = min(abs(x));

cdf = cumsum(y)*dx;

for i = 1:index_0
    i_plus = index_0 + i;
    i_minus = index_0 - i;
    if i_plus >= length(x) || i_minus <= 1
        break;  
    end
    if cdf(i_plus) - cdf(i_minus) >= value
        tindex = i_plus;
        tval = x(i_plus);
        return;
    end
end
fraction = cdf(end);
tindex = length(x);
tval = x(end);
end