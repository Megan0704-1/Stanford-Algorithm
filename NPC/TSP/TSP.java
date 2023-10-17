import java.io.*;
import java.util.*;

public class TSP{
    static double MAX = 1e8;
    static double ans = MAX;
    static int ncities;
    static double[][] location;
    static double[][] C;
    static double[][] A;

    public static void compute_len(){
        for(int i=1; i<=ncities; i++){
            for(int j=1; j<=ncities; j++){
                double locix = location[i][1];
                double lociy = location[i][2];
                double locjx = location[j][1];
                double locjy = location[j][2];

                C[i][j] = Math.sqrt(Math.pow(locix-locjx, 2)+Math.pow(lociy-locjy, 2));
            }
        }
        System.out.println("done compute len.\n");
    }

    public static void run_algo(){
        for(int i=1; i<=ncities; i++){
            System.out.println("visting: " + i);
            ans = Math.min(ans, dp(i, (1<<(ncities+1))-1)+C[i][1]);
        }
        System.out.println("the optimal solution: "+ ans);
    }

    public static double dp(int start, int vtx_comb){
        // this method compute the min dist from source 1 to dest start visiting every vtx in vtx_comb once.
        if(vtx_comb == ((1<<start) | 1)) return C[1][start];
        if(A[start][vtx_comb]!=0) return A[start][vtx_comb];

        double res = MAX;

        for(int k=1; k<=ncities; k++){
            if((vtx_comb & (1<<k))!=0 && k!=start && k!=1){
                int new_state = vtx_comb& (~(1<<start));
                res = Math.min(res, dp(k, new_state)+C[k][start]);
            }
        }
        A[start][vtx_comb] = res;
        return res;
    }

    public static void main(String[] argv){
        try{
            Scanner sc = new Scanner(new File(System.console().readLine()));
            ncities = sc.nextInt();
            C = new double[ncities+1][ncities+1];
            A = new double[ncities+1][1<<(ncities+1)];
            location = new double[ncities+1][3];

            for(int i=1; i<=ncities; i++){
                for(int j=1; j<=2; j++){
                    location[i][j] = sc.nextDouble();
                }
            }

            compute_len();
            run_algo();
        } catch (FileNotFoundException e){
            System.out.println("File not found.\n");
        }
    }
}