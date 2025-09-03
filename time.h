struct timespec {
    long int time_sec;
    long int time_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
