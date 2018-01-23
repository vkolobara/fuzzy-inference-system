import matplotlib.pyplot as plt

def plot_lang_var(lines):
    (tp, name, domain) = lines[0].split("\t")
    (start, step, end) = [int(x) for x in domain.split(",")]
    plt.close()
    plt.ylabel(r"$\mu(x)$")
    plt.xlabel("x") 
    plt.title(name)
    plt.ylim(0, 1.1)

    for line in lines[1:]:
        (name, func, vals) = line.split("\t")
        vals = [int(val) for val in vals.split(",")]
        xs = list(range(start,end,step))
        if func == "L":
            (alpha, beta) = vals
            plt.plot(xs, [L(x, alpha, beta) for x in xs], label=name)
            plt.xlim(start, beta+100)
        elif func == "LAMBDA":
            (alpha, beta, gamma) = vals
            plt.plot(xs, [Lambda(x, alpha, beta, gamma) for x in xs], label=name)
            plt.xlim(start, gamma+100)
        elif func == "GAMMA":
            (alpha, beta) = vals
            plt.plot(xs, [Gamma(x, alpha, beta) for x in xs], label=name)
            plt.xlim(start, beta+100)
        elif func == "PI":
            (alpha,beta,gamma,delta) = vals
            plt.plot(xs, [Pi(x, alpha, beta,gamma,delta) for x in xs], label=name)
            plt.xlim(start, delta+100)

    plt.legend()
    plt.show()

def L(x, alpha, beta):
    if x < alpha:
        return 1
    elif x >= beta:
        return 0
    return (beta - x) / (beta - alpha)

def Lambda(x, alpha, beta, gamma):
    if x < alpha or x >= gamma:
        return 0
    elif x < beta and x >= alpha:
        return (x - alpha) / (beta - alpha)
    return (gamma - x) / (gamma - beta)

def Gamma(x, alpha, beta):
    if x < alpha:
        return 0
    elif x >= beta:
        return 1
    return (x - alpha) / (beta - alpha)

def Pi(x, alpha, beta, gamma, delta):
    if x < alpha:
        return 0
    elif x < gamma and x >= beta:
        return 1
    elif x < beta and x >= alpha:
        return (x - alpha) / (beta - alpha)
    return (delta - x) / (delta - gamma)

def S(x, alpha, beta, gamma):
    pass

def Gauss(x, mu, sigma):
    pass

def Sigmoid(x, a, c):
    pass

def Exponential(x, mu, k):
    pass


test = ["IN\tL\t0,1,1300", 
        "small\tL\t20,50", 
        "medium\tLAMBDA\t40,60,100", 
        "large\tGAMMA\t90,150"
        ]

with open("../fuzzy-inference-system/democonf/lang_variables.conf") as f:
    content = f.read()
    split = content.split("\n\n")
    for l in split:
        plot_lang_var(l.split("\n"))

