int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (D - B) * (C - A) + (H - F) * (G - E);
        int left = max(A, E), bot = max(B, F);
        if (left >= min(G, C) || bot >= min(D, H) ) {return area;}
        else {
            return area - (min(G, C) - left) * (min(D, H) - bot);
        }
    }
