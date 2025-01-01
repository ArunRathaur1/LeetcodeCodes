class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Clamp the circle's center to the rectangle's bounds
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        // Calculate the distance from the circle's center to this closest point
        int distanceSquared = (closestX - xCenter) * (closestX - xCenter) +
                              (closestY - yCenter) * (closestY - yCenter);
        
        // Check if the distance is less than or equal to the circle's radius squared
        return distanceSquared <= radius * radius;
    }
};
