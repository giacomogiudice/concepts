function output = toNcol(adjacency,threshold)
% Computes Ncol array of non-zero indexes of binarized adjacency matrix
filtered = adjacency;
filtered(filtered < threshold) = 0;
filtered(filtered > 0) = 1;

[x y] = ind2sub(size(filtered),find(triu(filtered)));
output = [x y];