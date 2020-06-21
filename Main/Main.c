#include "../Libs/libs.h"

int main(){
    FILE *fr1, *fr2, *fw1, *fw2;

    char tmpname[300];
    char in_traj_filename[200];
    char in_traj_folder[200] = "../Traj_w_xnu_selected_extr50/";
    char in_traj_PATH[200];

    char out_traj_folder[200] = "../OutFiles/Traj_selected_extr50_w_rates/";
    char out_traj_PATH[200];

    int filecount;

    filecount = 0;
    fr1 = fopen("../OutFiles/trajectory_names_selected.txt", "r");
    while(fscanf(fr1, "%s",in_traj_filename)!=EOF){
        printf("%s\n",in_traj_filename);
        ++filecount;

        strcpy(in_traj_PATH, in_traj_folder);
        //strcat(in_traj_PATH, "trajectory.dat");
        strcat(in_traj_PATH, in_traj_filename);

        strcpy(out_traj_PATH, out_traj_folder);
        //strcat(out_traj_PATH, "trajectory.dat");
        strcat(out_traj_PATH, in_traj_filename);

        master(in_traj_PATH, out_traj_PATH);

        printf("<file-id>: %d\tfilename: %s <done>\n", filecount,in_traj_filename);

    }
    fclose(fr1);
    return(0);
}
