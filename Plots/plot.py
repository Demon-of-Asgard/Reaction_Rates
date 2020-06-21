#!/home/demon/anaconda3/bin/python3

import matplotlib.pyplot as plt
import numpy as np 


plt.rc('text', usetex=True)
plt.style.use('seaborn-white')

params = {'legend.fontsize': 3.5,'legend.handlelength': 2,"legend.framealpha":.90}
plt.rcParams.update(params)

name = "162633"
root = "../OutFiles/Traj_selected_extr50_w_rates/"
file = root + "trajectory.dat"+name

data = np.genfromtxt(file)

fig, axs = plt.subplots(2, 2)
fig.tight_layout(pad=3.0)
plt.suptitle("Trajectory: "+name, fontsize=7.5)
lz = 6.5

#Bin
ax = axs[0][0]
ax.tick_params(labelsize=lz, direction='in', length=2, width=.5, colors='k', grid_color='r', grid_alpha=0.5)

ax.plot(data[:, 0], data[:, 21]/1e-41, "r-", linewidth=0.5, label="$bin-\\sigma_{\\nu_e}$")
ax.plot(data[:, 0], data[:, 22]/1e-41, "b-", linewidth=0.5, label="$bin-\\sigma_{\\bar\\nu_e}$")
ax.plot(data[:, 0], data[:, 23]/1e-41, "r-.",linewidth=0.5, label="$bin-\\sigma_{e}$")
ax.plot(data[:, 0], data[:, 24]/1e-41, "b-.",linewidth=0.5, label="$bin-\\sigma_{\\bar e}$")
ax.set_ylabel("$\\sigma/(10^{-41}cm^2)$",fontsize = 6.0)
ax.set_xlabel("$t[s]$", fontsize=6.0)
ax.legend(frameon=False)



ax = axs[0][1]
ax.tick_params(labelsize=lz, direction='in', length=2, width=.5, colors='k', grid_color='r', grid_alpha=0.5)

ax.plot(data[:, 0], data[:, 25], "r-", linewidth=0.5, label="$bin-\\lambda_{\\nu_e}$")
ax.plot(data[:, 0], data[:, 26], "b-", linewidth=0.5,label="$bin-\\lambda_{\\bar\\nu_e}$")
ax.plot(data[:, 0], data[:, 27], "r-.",linewidth=0.5, label="$bin-\\lambda_{e}$")
ax.plot(data[:, 0], data[:, 28], "b-.", linewidth=0.5,label="$bin-\\lambda_{\\bar e}$")
ax.set_ylabel("$\\lambda[s^{-1}]$", fontsize=6.0)
ax.set_xlabel("$t[s]$", fontsize=6.0)
ax.legend(frameon=False)


#Ray
ax = axs[1][0]
ax.tick_params(labelsize=lz, direction='in', length=2, width=.5, colors='k', grid_color='r', grid_alpha=0.5)
ax.plot(data[:, 0], data[:, 29]/1e-41, "r-", linewidth=0.5, label="$ray-\\sigma_{\\nu_e}$")
ax.plot(data[:, 0], data[:, 30]/1e-41, "b-", linewidth=0.5, label="$ray-\\sigma_{\\bar\\nu_e}$")
ax.plot(data[:, 0], data[:, 31]/1e-41, "r-.",linewidth=0.5, label="$ray-\\sigma_{e}$")
ax.plot(data[:, 0], data[:, 32]/1e-41, "b-.", linewidth=0.5, label="$ray-\\sigma_{\\bar e}$")
ax.set_ylabel("$\\sigma/(10^{-41}cm^2)$", fontsize=6.0)
ax.set_xlabel("$t[s]$", fontsize=6.0)
ax.legend(frameon=False)

ax = axs[1][1]
ax.tick_params(labelsize=lz, direction='in', length=2, width=.5, colors='k', grid_color='r', grid_alpha=0.5)

ax.plot(data[:, 0], data[:, 33], "r-", linewidth=0.5, label="$ray-\\lambda_{\\nu_e}$")
ax.plot(data[:, 0], data[:, 34], "b-", linewidth=0.5, label="$ray-\\lambda_{\\bar\\nu_e}$")
ax.plot(data[:, 0], data[:, 35], "r-.", linewidth=0.5, label="$ray-\\lambda_{e}$")
ax.plot(data[:, 0], data[:, 36], "b-.", linewidth=0.5, label="$ray-\\lambda_{\\bar e}$")
ax.set_ylabel("$\\lambda[s^{-1}]$", fontsize=6.0)
ax.set_xlabel("$t[s]$", fontsize=6.0)
ax.legend(frameon=False)

plt.savefig(name+".png")
plt.show()

