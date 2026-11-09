class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c,
             int color, int original) {

        int m = image.size();
        int n = image[0].size();

        if(r < 0 || c < 0 || r >= m || c >= n)
            return;

        if(image[r][c] != original)
            return;

        image[r][c] = color;

        dfs(image, r+1, c, color, original);
        dfs(image, r-1, c, color, original);
        dfs(image, r, c+1, color, original);
        dfs(image, r, c-1, color, original);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int original = image[sr][sc];

        if(original == color) return image;

        dfs(image, sr, sc, color, original);

        return image;
    }
};