######################################################
### Stage 1 - Base image (development environment) ###
######################################################
# Use the image i've already created, just from dockerhub.
# How & why we've build this image? 
# Checkout this medium article: https://medium.com/@lior.dux/c-programming-all-over-again-b9984a4736c5
# Github Repository: https://github.com/zMynxx/c-all-over-again
# Dockerhub: https://hub.docker.com/r/druxx/ubuntu-ceedling
FROM druxx/ubuntu-ceedling:22.04-v0.32.0-d76db35 as ase 
COPY project /project
WORKDIR /project
CMD bash

###########################################################
### Stage 2 - Build image (compile, generate artifacts) ###
###########################################################
# use the image i've already created using the base stage, just from dockerhub
FROM druxx/ubuntu-ceedling:22.04-v0.32.0-d76db35 as build 
COPY --from=base /project/src /project/src
COPY --from=base /project/project.yml /project/project.yml
WORKDIR /project
CMD ceedling release

##########################################################
### Stage 3 - Production image (serve our application) ###
##########################################################
FROM scratch as release

# Use COPY to pull artifact from previous build layer
COPY --from=base /project/build/artifacts/release/MyApp.out /bin/MyApp.out
ENTRYPOINT ["/bin/MyApp.out"]
