/**
 * @file ans.c
 * @brief
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 * Assume that the total area is never beyond the maximum possible value of int.
 *
 * @version
 * @date 2015-08-14 16:16
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area1 = (C - A) * (D - B);
    int area2 = (G - E) * (H - F);

    int x0 = A > E ? A : E;
    int y0 = B > F ? B : F;
    int x1 = C < G ? C : G;
    int y1 = D < H ? D : H;

    int commonArea = 0;
    if (x1 >= x0 && y1 >= y0)
        commonArea = (x1 - x0) *(y1 - y0);

    return area1 + area2 - commonArea;
}

