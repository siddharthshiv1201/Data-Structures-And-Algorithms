class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty)
            if (tx < ty)
                ty %= tx;
            else
                tx %= ty;

      if(sx == tx && sy <= ty && (ty - sy) % sx == 0)
            return true; 
        
         return sy == ty && sx <= tx && (tx - sx) % sy == 0;
    }
};

            
                   