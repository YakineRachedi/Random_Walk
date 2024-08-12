import matplotlib.pyplot as plt

def PlotRW(filename):
    x = []
    y = []
    with(open(filename,'r')) as file:
        for line in file:
            lines = line.split()
            x.append(float(lines[0]))
            y.append(float(lines[1]))
    return x,y

x1,y1 = PlotRW("RW.dat")
x2,y2 = PlotRW("RWMin.dat")

fig, (ax1, ax2) = plt.subplots(1,2, figsize = (12,6))

# Plotting the random walk
ax1.plot(x1, y1, label='Random Walk Path')
ax1.set_xlabel('Time')
ax1.set_ylabel('Position')
ax1.set_title('Random Walk Over Time')
ax1.legend()
ax1.grid(True)

# Plotting the random walk with minimum
ax2.plot(x2, y2, label='Random Walk with Minimum')
ax2.set_xlabel('Time')
ax2.set_ylabel('Minimum Position')
ax2.set_title('Random Walk with Minimum Over Time')
ax2.legend()
ax2.grid(True)

plt.tight_layout()
plt.savefig("RandomWalk.png")
plt.show()