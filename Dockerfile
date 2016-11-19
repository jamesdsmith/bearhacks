FROM jupyter/notebook

USER root

RUN npm install -g ijavascript

CMD ijs --ip=* --debug

EXPOSE 8888

