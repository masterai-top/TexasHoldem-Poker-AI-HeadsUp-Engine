import os
import signal
import time


class TaskManager:
    def __init__(self,name):
        self.is_master= True
        self.children={}
        self.name = name
        self.alive = True
        self.reg_signals()
        self.jobs = []
        self.idx = 0
        self.task = None
    def set_job(self,jobs):
        self.jobs = jobs
    def make_child(self,n):
        pid = os.fork()
        if pid == 0:
            self.is_master = False
            self.children = {}
            self.idx = n
            self.name = "child-%d"%(n,)
            if n<len(self.jobs):
                self.task = self.jobs[n]()
        else:
            self.children[n] = pid
    def reg_signals(self):
        def s(a,b):
            print("%s get sigusr1"%(self.name,))
            self.alive= False
            if self.is_master:
                for i,pid in self.children.items():
                    os.kill(pid, signal.SIGUSR1)
        signal.signal(signal.SIGUSR1,s)
    def master_task(self):
        self.check_children()
        time.sleep(1)
    def child_task(self):
        if self.task:
            self.task.run()
        else:
            time.sleep(1)
    def check_children(self):
        for i,pid in self.children.items():
            is_alive = True
            try:
                r=os.waitpid(pid, os.WNOHANG)
                if type(r)==tuple and r[0] == pid:
                    is_alive = False
                #print("child %d ret %s"%(pid,str(r)))
            except OSError as e:
                is_alive = False
                print(e)
            except ProcessLookupError as e:
                is_alive = False
                print(e)
            if not is_alive:
                print("child %d miss"%(i,))
                self.make_child(i)

    def gen(self,n):
        for i in range(0,n):
            self.make_child(i)
            if not self.is_master:
                break

    def run(self):
        while self.alive:
            if self.is_master:
                self.master_task()
            else:
                self.child_task()


#if __name__=='__main__':
    #t = Task('master')
    #t.gen(2)
    #t.run()