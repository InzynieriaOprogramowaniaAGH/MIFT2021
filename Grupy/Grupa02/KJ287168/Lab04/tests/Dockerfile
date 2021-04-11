FROM deltachat-core:latest


WORKDIR ./deltachat-core-rust/python
RUN pip3 install pytest pytest-xdist pytest-timeout pytest-rerunfailures requests && \
	 pytest -v tests

