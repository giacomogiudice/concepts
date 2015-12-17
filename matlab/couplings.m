function [arr,vec] = couplings(vec)
if iscellstr(vec)
    vec = load(vec);
end
f_ind = [];
row = 1;
ind = 1;
while ind <= length(vec)
    f_ind(end + 1) = ind;
    row = row + 1;
    ind = ind + row;
    
end
vec(f_ind) = [];

arr = triu(ones(row - 1), 1);
arr(arr == 1) = vec;
arr = arr + arr';
end
